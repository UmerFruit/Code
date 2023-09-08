/*
 * Block.h
 *
 *  Created on: Mar 8, 2023
 *      Author: umer
 */

#ifndef BLOCK_H_
#define BLOCK_H_
#include <iostream>
#include <string>
using namespace std;

class Block
{
private:
	float length;
	float width;
	float height;
	string color;
	const string material;
public:
	static int countOfBlocks;
	Block(float = 2,float = 2, float = 2, string = "Black", string = "Card");
	const string& getColor() const;
	void setColor(const string &color);
	int getCountOfBlocks();
	float getHeight() const;
	void setHeight(float height);
	float getLength() const;
	void setLength(float length);
	float getWidth() const;
	void setWidth(float width);
	float getVolume();
	float getSurfaceArea();
	void print();
	const string getMaterial() const;

};
int Block::countOfBlocks=0;

inline const string Block::getMaterial() const {
	return material;
}




void Block::print()
{
	cout<<"Lenght = "<<length<<endl;
	cout<<"Width = "<<width<<endl;
	cout<<"Height = "<<height<<endl;
	cout<<"Color = "<<color<<endl;
	cout<<"Material = "<<length<<endl;
	cout<<"Surface Area = "<< getSurfaceArea() <<endl;
	cout<<"Volume = "<<getVolume()<<endl;


}

float Block::getVolume()
{
	return length*width*height;
}
float Block::getSurfaceArea()
{
	float SA=2*(length*width + length*height + width*height);
	return SA;
}

Block::Block(float length,float width, float height, string color, string mat):material(mat)
{
	this->length = length;
	this->width = width;
	this->height = height;
	this->color = color;
	countOfBlocks++;
}

inline const string& Block::getColor() const {
	return color;
}

inline void Block::setColor(const string &color) {
	this->color = color;
}

inline int Block::getCountOfBlocks(){
	return countOfBlocks;
}

inline float Block::getHeight() const {
	return height;
}

inline void Block::setHeight(float height) {
	this->height = height;
}

inline float Block::getLength() const {
	return length;
}

inline void Block::setLength(float length) {
	this->length = length;
}

inline float Block::getWidth() const {
	return width;
}

inline void Block::setWidth(float width) {
	this->width = width;
}





#endif /* BLOCK_H_ */
