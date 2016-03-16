/*
 * CTECArray.h
 *
 *  Created on: Feb 2, 2016
 *      Author: emad6932
 */

/*
 * Created on: Feb 2, 2016
 * 		Author: Easton Madsen
 * 		Version: 0.1
 */

#ifndef MODEL_CTECARRAY_H_
#define MODEL_CTECARRAY_H_

#include "ArrayNode.h"

template<class Type>
class CTECArray
{
private:
	int size;
	int length;
	ArrayNode<Type> * head;
public:
	CTECArray(int length);
	virtual ~CTECArray();
	int getSize();
	Type get(int position);
	void set(int position ,const Type& value);
    int indexOf(Type value);
};

#endif /* MODEL_CTECARRAY_H_ */
