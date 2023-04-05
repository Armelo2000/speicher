#include "CircularBuffer.h"

CircularBuffer::CircularBuffer(uint32_t count): m_writePos(0), m_readPos(0), m_maxCount(count),
												m_currentCount(0), m_full(false){

}


/***************************************************
 * Diese Routine gibt den Status von Ring zurück
 *   - false, falls der ring nicht voll ist
 *   - true, falls der ring voll geschrieben wurde
 ***************************************************/
bool CircularBuffer::getCircularBufferState(){
	return this->m_full;
}

/***************************************************
 * Diese Routine gibt die maximal festgelegte Anzahl
 * von Objekte die im Ring gespeichert werden können
 ***************************************************/
uint32_t CircularBuffer::getMaxCount(){
	return this->m_maxCount;
}

/***************************************************
 * Diese Routine gibt die aktuelle Anzahl von Objekte
 * im Ring Speicher.
 ***************************************************/
uint32_t CircularBuffer::getCurrentCount(){
	return this->m_currentCount;
}

/***************************************************
 * Diese Routine setzt der Ring Speicher zurück
 ***************************************************/
void CircularBuffer::reset(){
	this->m_writePos = 0;
	this->m_readPos = 0;
	this->m_full = false;
	this->m_currentCount = 0;

}

/***************************************************
 * Diese Routine aktualisiert die Position für das
 * Schreibzugriff
 **************************************************/
void CircularBuffer::updateWritePosition()
{

	if (++(this->m_writePos) == this->m_maxCount)
	{
		this->m_writePos = 0;

		//Der Ring Speicher ist voll
		if(!this->m_full){
			this->m_full = true;
		}
	}

	if(this->m_currentCount < this->m_maxCount){
		this->m_currentCount++;
	}
}

/***************************************************
 * Diese Routine aktualisiert die Position für das
 * Lesezugriff
 **************************************************/
void CircularBuffer::updateReadPosition(){

	if(this->m_full)
   	{
		if(this->m_readPos == 0){
			//Zurück an den letzte index im ring Speicher falls der Ring voll ist
			//Es wird von unten nach oben gelesen. die neueste Information zuerst
			this->m_readPos = this->m_maxCount - 1;

		}else{
			this->m_readPos--;
		}
	}else{
		if(this->m_readPos > 0){
			this->m_readPos--;
		}
	}

}

/***************************************************
 * Diese Routine aktualisiert die Position für das
 * Lesezugriff auf x elemente im Ring Speicher
 **************************************************/
void CircularBuffer::updateReadPosition(uint32_t number){

	//Position für Lesezugriff aktualisieren
	//Das lesen fängt vom Letzten geschriebenen Objekt an
	this->m_readPos = this->m_writePos;

	for(uint32_t i = 0; i<number; i++){
		this->updateReadPosition();
	}

}

/***************************************************
 * Diese Routine setzt die Position für das
 * Lesezugriff auf dem zuletzt geschriebene Eintrag
 **************************************************/
void CircularBuffer::startToRead(){
	if(this->m_full){
		if(this->m_writePos > 0){
			this->m_readPos = this->m_writePos - 1;
		}else{
			this->m_readPos = this->m_maxCount - 1;
		}
	}else{
		if(this->m_writePos > 0){
			this->m_readPos = this->m_writePos - 1;
		}else{
			this->m_readPos = 0;
		}
	}
}
