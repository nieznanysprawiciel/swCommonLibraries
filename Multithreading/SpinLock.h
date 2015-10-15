#include "Common/TypesDefinitions.h"

/**
@defgroup Multithreading Narz�dzia pomocnicze do obs�ugi wielow�tkowo�ci.
@ingroup CommonFiles
*/

/**
@brief Klasa s�u��ca jako mutex z aktywnym oczekiwaniem.

Klasa SpinLock u�ywa aktywnego oczekiwania w celu unikni�cia konieczno�ci
odwo�ywania si� do systemu operacyjnego, gdy wej�cie do sekcji krytycznej nie jest mo�liwe.
Implementacj� opiera si� o instrukcj� TSL.

Mo�liwe jest u�ywanie klasy we wsp�pracy z mechanizmami takimi jak std::lock_guard.

Ze wzgl�du na to, �e Visual Studio nie potrafi kompilowa� asemblera pod architektur� ARM,
na razie klasa nadaje si� do u�ytku jedynie pod procesorami x86.
*/
class SpinLock
{
private:
	volatile int16		m_locked;
protected:
public:
	SpinLock()
	{
		m_locked = 0;
	}
	~SpinLock() = default;

	inline void lock();
	inline void unlock();
	inline bool try_lock();
};


/**@brief Wej�cie do sekcji krytycznej.
*/
inline void SpinLock::lock()
{
	_asm
	{
		mov			ecx,			[this]
	TRY_LOCK_LABEL:
		mov			AX,				0xF
		xchg		AX,				[ecx].m_locked
		cmp			AX,				0x0
		jne			TRY_LOCK_LABEL
	}
}


/**@brief Opuszczenie sekcji krytycznej.
*/
inline void SpinLock::unlock()
{
	_asm mov		ecx,		[this]
	_asm mov		EAX,		0x0
	_asm xchg		AX,			[ecx].m_locked
}


/**@brief Pr�buje zaj�� sekcj� krytyczn�. Je�eli jest zaj�ta, wychodzi natychmiast.

@return Zwraca true, je�eli uda�o si� wej�� do sekcji krytycznej.
*/
inline bool SpinLock::try_lock()
{
	bool success = false;
	_asm
	{
		mov			ecx,			[this]
		mov			AX,				0xF
		xchg		AX,				[ecx].m_locked
		cmp			AX,				0x0
		jne			LOCK_FAILED_LABEL
	}
	return true;
	LOCK_FAILED_LABEL:
	return false;
}

