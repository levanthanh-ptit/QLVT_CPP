using namespace std;
struct Thongtin_CT{
	char MAVT[20];
	char soluong[20];
	char Dongia[20];
	char VAT[10];
};
struct NodeCT{
	Thongtin_CT thongtin;
	NodeCT* _next;
};
struct CT_HoaDon{
	int num = 0;
	NodeCT* ctHead;
};
int j = 1;
void init_ct(CT_HoaDon &ct){
	ct.num = 0;
	ct.ctHead = NULL;
}
NodeCT* GetNode_CT(Thongtin_CT ct){
	NodeCT* p = new NodeCT;
	p->thongtin = ct;
	p->_next = NULL;
	return p;
}
void addTail_CT(CT_HoaDon &ct,NodeCT* nodect){
	if(ct.ctHead == NULL) ct.ctHead = nodect;
	else{
		NodeCT* p = new NodeCT;
		p =	ct.ctHead;
		
		while(p->_next != NULL){
			p = p->_next;
		}
		p->_next = nodect;
		
	}
	ct.num++;
}
