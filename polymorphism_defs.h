//
// Created by shira on 10/7/19.
//

#ifndef CPP_UTH_ENCAPSULATION_SHIRAZALTSMAN_POLYMORPHISM_DEFS_H
#define CPP_UTH_ENCAPSULATION_SHIRAZALTSMAN_POLYMORPHISM_DEFS_H

#include <stdio.h>

typedef void* (*ptrFunVT) (void*, ...);

typedef ptrFunVT* VirtualTable;
//
//inline void printFunc(const char* fname)
//{
//    printf("%-60s | ", fname);
//}
//
////// TextFormatter ////////////

struct TextFormatter_VT;

typedef struct {
     VirtualTable vptr;
} TextFormatter;

typedef struct {
    void(*dtor)(TextFormatter* this);
    void (*p_TF_print)(const TextFormatter *this, const char *text);
} TextFormatter_VT;


void TF_print(const TextFormatter *this, const char *text);
void TextFormatterCTOR(TextFormatter *this);
void TextFormatterDTOR(TextFormatter *this);




struct DefaultTextFormatter_VT;
typedef struct {
    TextFormatter inher;
    struct {
        //static int next_id;
        //static int getId() { return next_id++; }
    } Ider;
    int id;
    struct DefaultTextFormatter_VT *vptr;

} DefaultTextFormatter;
struct DefaultTextFormatter_VT{
    void(*dtor)(TextFormatter* this);
    void (*p_print)(const TextFormatter *this, const char *text);
};

void DefaultTextFormatterCTOR(DefaultTextFormatter *this);

void DefaultTextFormatterCOPYCTOR(DefaultTextFormatter *this, const DefaultTextFormatter *other);

void DefaultTextFormatterASSIGHN(DefaultTextFormatter *this, const DefaultTextFormatter *other);

void DefaultTextFormatterDTOR(DefaultTextFormatter *this);

int next_id;

typedef struct {

} DefaultTextFormatter_VT;


////// DefaultTextFormatter ////////////
//
//class DefaultTextFormatter: public TextFormatter
//        {
//                public:
//                DefaultTextFormatter();
//        DefaultTextFormatter(const DefaultTextFormatter&);
//        DefaultTextFormatter& operator=(const DefaultTextFormatter&);
//        ~DefaultTextFormatter();
//
//        virtual void print(const char* text) const;
//
//        private:
//        class Ider
//        {
//            private:
//            static int next_id;
//            public:
//            static int getId() { return next_id++; }
//        };
//
//        const int id;
//        };
//
//DefaultTextFormatter* generateFormatterArray();
//
//
////// PrePostFixer ////////////
//
//class PrePostFixer: public DefaultTextFormatter
//        {
//                public:
//                PrePostFixer(const char* prefix, const char* postfix);
//        ~PrePostFixer();
//
//        virtual void print(const char* text) const;
//        virtual void print(long num, char symbol = '\0') const;
//
//        virtual char getDefaultSymbol() const;
//
//        protected:
//        const char* getPrefix() const;
//        const char* getPostfix() const;
//
//        private:
//        void print_num(long num) const;
//        void print_num(long num, char symbol) const;
//
//        const char* pre;
//        const char* post;
//        };
//
////// PrePostFixer Defs ////////////
//
//inline const char* PrePostFixer::getPrefix() const
//{
//return pre;
//}
//
//inline const char* PrePostFixer::getPostfix() const
//{
//return post;
//}
//
//inline char PrePostFixer::getDefaultSymbol() const
//{
//return '\0';
//}
//
//inline void PrePostFixer::print(long num, char symbol) const
//{
//printFunc("[PrePostFixer::print(long, char)]");
//printf("-->\n");
//
//if (symbol)
//print_num(num, symbol);
//else
//print_num(num);
//}
//
//inline void PrePostFixer::print_num(long num) const
//{
//printFunc("[PrePostFixer::print_num(long)]");
//printf("%s%ld%s\n", pre, num, post);
//}
//
//inline void PrePostFixer::print_num(long num, char symbol) const
//{
//printFunc("[PrePostFixer::print_num(long, char)]");
//printf("%s%c%ld%s\n", pre, symbol, num, post);
//}
//
//
////// PrePostDollarFixer ////////////
//
//class PrePostDollarFixer: public PrePostFixer
//        {
//                protected:
//                static const char DEFAULT_SYMBOL = '$';
//
//                public:
//                PrePostDollarFixer(const char* prefix, const char* postfix);
//                PrePostDollarFixer(const PrePostDollarFixer& other);
//                ~PrePostDollarFixer();
//
//                void print(int num, char symbol = DEFAULT_SYMBOL) const;
//                void print(long num, char symbol = DEFAULT_SYMBOL) const;
//                void print(double num, char symbol = DEFAULT_SYMBOL) const;
//                char getDefaultSymbol() const;
//        };
//
////// PrePostDollarFixer Defs ////////////
//
//inline char PrePostDollarFixer::getDefaultSymbol() const
//{
//return DEFAULT_SYMBOL;
//}
//
////// PrePostHashFixer ////////////
//
//class PrePostHashFixer: public PrePostDollarFixer
//        {
//                private:
//                static const char DEFAULT_SYMBOL = '#';
//                public:
//                PrePostHashFixer(int prc = 4);
//                ~PrePostHashFixer();
//
//                void print(int num, char symbol = DEFAULT_SYMBOL) const;
//                void print(long num, char symbol = DEFAULT_SYMBOL) const;
//                void print(double num, char symbol = DEFAULT_SYMBOL) const;
//                char getDefaultSymbol() const;
//
//                private:
//                int precision;
//        };
//
////// PrePostHashFixer Defs ////////////
//
//inline void PrePostHashFixer::print(double num, char symbol) const
//{
//printFunc("[PrePostHashFixer::print(double, char)]");
//
//printf("%s[%c%.*f]%s\n", getPrefix(), symbol, precision, num, getPostfix());
//}
//
//inline char PrePostHashFixer::getDefaultSymbol() const
//{
//return DEFAULT_SYMBOL;
//}
//
//
////// PrePostFloatDollarFixer ////////////
//
//class PrePostFloatDollarFixer: public PrePostDollarFixer
//        {
//                protected:
//                static const char DEFAULT_SYMBOL = '@';
//
//                public:
//                PrePostFloatDollarFixer(const char* prefix, const char* postfix);
//                ~PrePostFloatDollarFixer();
//                void print(float num) const;
//                void print(float num, char symbol) const;
//                char getDefaultSymbol() const;
//        };
//
////// PrePostFloatDollarFixer Defs ////////////
//
//inline char PrePostFloatDollarFixer::getDefaultSymbol() const
//{
//return DEFAULT_SYMBOL;
//}
//
////// PrePostChecker ////////////
//
//class PrePostChecker: public PrePostFloatDollarFixer
//        {
//                public:
//                PrePostChecker();
//        ~PrePostChecker();
//
//        void printThisSymbolUsingFunc() const;
//        void printThisSymbolDirectly() const;
//        void printDollarSymbolByCastUsingFunc() const;
//        void printDollarSymbolByScopeUsingFunc() const;
//        void printDollarSymbolByCastDirectly() const;
//        void printDollarSymbolByScopeDirectly() const;
//        };
//
//
////// Multiplier ////////////
//
//class Multiplier: public DefaultTextFormatter
//        {
//                public:
//                Multiplier(int t = 2);
//        ~Multiplier();
//
//        void print(const char*) const;
//        int getTimes() const;
//        void setTimes(int);
//        private:
//        int times;
//        };
//
////// Multiplier Defs ////////////
//
//inline Multiplier::Multiplier(int t)
//:   times(t)
//        {
//                printf("--- Multiplier CTOR: times = %d\n", times);
//        }
//
//inline Multiplier::~Multiplier()
//{
//    printf("--- Multiplier DTOR: times = %d\n", times);
//}
//
//inline int Multiplier::getTimes() const
//{
//return times;
//}
//
//inline void Multiplier::setTimes(int t)
//{
//    times = t;
//}


#endif //CPP_UTH_ENCAPSULATION_SHIRAZALTSMAN_POLYMORPHISM_DEFS_H
