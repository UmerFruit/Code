/*
 * Matrix.cpp
 *
 *  Created on: 25-Mar-2023
 *      Author: umerfarooq
 */

#include "Matrix.cpp"
int main()
{
     int scalar;
     Matrix m1;
     m1.setMat();
     Matrix m2;
     m2.setMat();
     cout << "Displaying matrix 1:\n\n";
     cout << m1 << endl;

     cout << "Displaying matrix 2:\n\n";
     cout << m2 << endl;

     cout << "Performing matrix1 + matrix 2:\n";
     cout << m1 + m2 << endl;

     cout << "Performing matrix1 - matrix2:\n";
     cout << m1 - m2 << endl;

     cout << "Enter Scaler value" << endl;
     cin >> scalar;
     cout << "Peforming matrix1 * scalar:\n";
     cout << m1 * scalar << endl;

     cout << "Enter Scaler value" << endl;
     cin >> scalar;
     cout << "Peforming matrix2 * scalar:\n";
     cout << m2 * scalar << endl;

     cout << "Performing matrix1 * matrix2:\n";
     cout << m1 * m2 << endl;

     cout << "Performing matrix1 == matrix2:\n";
     cout << (m1 == m2) << endl;

     cout << "Copying matrix1 into a new matrix object, matrix3\n";
     Matrix m3(m1.getRows(), m1.getColumns());
     cout << "Displaying matrix 3:\n\n";
     cout << m3 << endl;

     cout << "Now performing matrix3 = matrix1\n"<<endl;
     m3 = m1;
     cout << "Displaying matrix 3:\n\n";
     cout << m3 << endl;

     cout << "Updating matrix 1 as follows:";
     m1.setMat();
     cout << "Displaying matrix 3 again:\n\n";
     cout << m3 << endl;
     cout << "Displaying matrix 1 again:\n\n";
     cout << m1 << endl;

     cout << "Demo of assignment operator complete.\n";
     
     cout << "Performing matrix1++:\n\n";
     cout << m1++ << endl;

     cout << "Performing ++matrix2:\n\n";
     cout << ++m2 << endl;

     cout << "Performing matrix3 = ++matrix1;\n\n";
     m3 = (++m1);
     cout << "Displaying matrix 3:\n\n";
     cout << m3 << endl;
     cout << "Displaying matrix 1:\n\n";
     cout << m1 << endl;

     cout << "Performing matrix3 = matrix1++;\n\n";
     m3 =( m1++);
     cout << "Displaying matrix 3:\n\n";
     cout << m3 << endl;
     cout << "Displaying matrix 1:\n\n";
     cout << m1 << endl;
     
     cout << "Destroying all matrices.";
}