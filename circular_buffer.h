#include <stdint.h>


class CircularBuffer{

private:
	/******************************************************
	 * Position für das Schreibzugriff
	 ******************************************************/
	uint32_t m_writePos;

	/*****************************************************
	 * Position für den Lesezugriff
	 *****************************************************/
	uint32_t m_readPos;

	/***************************************************
	 * Maximal Anzahl von Objekte im Ring
	 **************************************************/
	uint32_t m_maxCount;

	/***************************************************
	 * Aktuelle Anzahl von Objekte im Ring speicher
	 * Falls der Ring Speicher voll ist, dann ist die
	 * Anzahl von m_currentCount gleich den maximal
	 * Anzahl von Objekte im Ring Speicher
	 **************************************************/
	uint32_t m_currentCount;

	/***************************************************
	 * Flag gibt an ob der Ring voll ist
	 ***************************************************/
	bool m_full;

public:
	CircularBuffer(uint32_t count);


	/***************************************************
	 * Diese Routine gibt den Status von Ring zurück
	 *   - false, falls der ring nicht voll ist
	 *   - true, falls der ring voll geschrieben wurde
	 ***************************************************/
	bool getCircularBufferState();

	/***************************************************
	 * Diese Routine gibt die maximal festgelegte Anzahl
	 * von Objekte die im Ring gespeichert werden können
	 ***************************************************/
	uint32_t getMaxCount();

	/***************************************************
	 * Diese Routine gibt die aktuelle Anzahl von Objekte
	 * im Ring Speicher.
	 ***************************************************/
	uint32_t getCurrentCount();

	/***************************************************
	 * Diese Routine setzt der Ring Speicher zurück
	 ***************************************************/
	void reset();

	/***************************************************
	 * Diese Routine aktualisiert die Position für das
	 * Schreibzugriff
	 **************************************************/
	void updateWritePosition();

	/***************************************************
	 * Diese Routine setzt die Position für das
	 * Lesezugriff auf dem zuletzt geschriebene Eintrag
	 **************************************************/
	void startToRead();

	/***************************************************
	 * Diese Routine aktualisiert die Position für das
	 * Lesezugriff
	 **************************************************/
	void updateReadPosition();

	/***************************************************
	 * Diese Routine aktualisiert die Position für das
	 * Lesezugriff auf x elemente im Ring Speicher
	 **************************************************/
	void updateReadPosition(uint32_t number);

};


