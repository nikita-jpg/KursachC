#ifndef BASE_H
#define BASE_H

//Новое
#include <vector>
#include <string>

using namespace std;

class Base;

typedef void (Base::* T_SIGNAL) ( string & );
typedef void (Base::* T_HENDLER) ( string );

//К_новое
class Base
{
	//Новое
	private:
		struct o_sh
		{
			Base* p_cl_base;
			T_SIGNAL p_signal;
			T_HENDLER p_hendler;
		};
		vector<o_sh* > connects;
	
	protected:
		int class_number;
		int status;
		string name;
		Base* parent;
	
	vector<Base*> children;
	//К_новое
	public:
		Base(Base* parent);
		Base(Base* parent, string name, int class_number, int status);
		void printChildren(bool i);
		void printHierarchyTree(bool i, int k);
		void setStatus(int status);
		void showTree();
	//Новое
		void set_connect(T_SIGNAL p_signal,
			Base* p_ob_hendler,
			T_HENDLER p_hendler);
	
		void delete_connect(T_SIGNAL p_signal,
			Base* p_ob_hendler,
			T_HENDLER p_hendler);
	
		void emit_signal(T_SIGNAL p_signal, string & s_command);

		static T_SIGNAL getSignal(int numberClass);
		static T_HENDLER getHendler(int numberClass);
		int getClassNumber();
	//К_новое
	
		int getStatus();
		string getName();
		string getPatchItem(string ObjectPath, int iLevel);
		Base* findParent(string name);
		Base* getObject(string objectPath);
		Base* getObjectByRootPath(string objectPath);
		Base* getObjectRoot();
		Base* getChild(string nameChild);
		~Base();
};

#define SIGNAL_D(T, signal_f ) (T_SIGNAL (&T::signal_f))
#define HENDLER_D(G, hendler_f ) (T_HENDLER (&G::hendler_f))

#endif