/** @file
 * @author Курбатов М.А.
 * @version 1.0
 * @date 10.12.2024
 * @copyright ИБСТ ПГУ
 * @brief Заголовочный файл для модуля e_d
 */
#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <UnitTest++/UnitTest++.h>
using namespace std;
/** @brief Шифрование методом табличной маршрутной перестановкой
 * @details Ключ устанавливается в конструкторе.
 * Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt.
 * @warning Реализация только для английского языка
 */
class e_d
{
private:
    int num_of_columns;
    /**
     * @brief Валидация ключа
     * @details Убирает из ключ всё кроме цифр.
     * Если ключ оказался пустым произойдёт повторный ввод значения ключа.
     * @param key Входной вектор символов, представляющий ключ
     */
    string getValidKey(vector<char>& key);
    /**
     * @brief Валидация текста
     * @details Убирает из текста все недопустимые символы, которых нет в алфавите.
     * @param stroka Входная строка, представляющая текст
     */
    string getValidText(string& stroka);
    /**
     * @brief Валидация ключа относительно текста
     * @details Если ключ меньше или равен длине строки, то значение ключа приравнивается к половине длины текста.
     * Если длина текста во много раз больше, чем ключ, то значение ключа приравнивается к половине длины текста.
     * @param key ключ
     * @param stroka Входная строка, представляющая текст
     */
    int getValid_num_of_columns(int key, string& stroka);
public:
	 /**
     * @brief Конструктор для установки ключа
     * @param key Входной вектор символов, представляющий ключ
     */
    e_d(vector<char> key);
    e_d() = delete; ///< Запрет на использование конструктора по умолчанию
    /**
 	* @brief Зашифровывание
 	* @param stroka Текст для зашифрования.
 	* Текст проходить валидацию текста.
 	* @return Зашифрованная строка
 	*/
    string encrypt(string stroka);
    /**
 	* @brief Расшифровывание
 	* @param stroka Текст для расшифрования.
 	* Текст проходить валидацию текста.
 	* @return Расшифрованная строка
 	*/
    string decrypt(string stroka);
};
