#ifndef NhanvienGUI_H
#define NhanvienGUI_H

#include "GeneralGUI.h"
#include "Nhanvien.h"
#include "SelectDataMenu.h"
#import "SelectDataMenu.h"
#include "Util.h"

int banner_size = 100;


class NhanVienAdapter : public SelectDataMenu {
	private:
		Holder<NhanVien> holder;
		
		void printNhanVien(NhanVien* nv){
			cout <<" Ma nhan vien  : " <<nv->info.MANV <<endl;
			cout <<" Ten nhan vien : " <<nv->info.HO <<" " <<nv->info.TEN <<endl;
			cout <<" Phai          : " <<nv->info.PHAI <<endl;
		}
		
		void deleteCurrent(){
			if(holder.count == 0) return;
			int currentIndex = getIndex();
			deleteNhanVien(DataNhanVien, holder.data[currentIndex]->info.MANV);
			log<<"current index "<<currentIndex <<endl;
			holder.deleteItem(currentIndex);
			
		}
		
		void insertNhanVien(){
			_clear();
			int MANV;
			char HO[100], TEN[100], PHAI[5];
			cout <<" Ma nhan vien  : ";
			cin >>MANV;
			fflush(stdin);
			cout <<" Ho            : ";
			cin.getline(HO, 100);
			cout <<" Ten nhan vien : ";
			cin.getline(TEN, 100);
			cout <<" Phai          : ";
			cin.getline(PHAI, 5);
			NodeNV* nv = newNodeNV(MANV, HO, TEN, PHAI);
			addNhanVien(DataNhanVien, nv);
			_clear();
			int i = 0;
			while(i < holder.count){
				if(holder.data[i]->info.MANV > MANV) break;
				else i++;
			}
			holder.insertItem(&(nv->nv), i);
		}
		
	public:
		NhanVienAdapter(int p_page_size, DsNhanVien &ds)
		:SelectDataMenu(p_page_size, ds.num)
		{
			holder.data = new NhanVien*[ds.num];
			if(ds.num>0) travelLNR(DataNhanVien._nhanvien, holder.data, holder.count );
			initListExtendAction(2);
			addExtendAction(KEY_F1, "F1: Xoa");
			addExtendAction(KEY_F2, "F2: Them");
		}
		
		void printElement(int i) override {
			cout <<i+1 <<".\n";
			printNhanVien(holder.data[i]);
		}
		
		bool onExtentAction(int key) override {
			switch(key) {
				case KEY_F1:
					deleteCurrent();
					return true;
				case KEY_F2:
					insertNhanVien();
					return true;
				default:
					return true;
			}	
		}
		
};

void nhanVien()
{
	_clear();
	NhanVienAdapter nhanVienAdapter = NhanVienAdapter(5, DataNhanVien);
	nhanVienAdapter.title = "QUAN LY NHAN VIEN";
	nhanVienAdapter.run();
}

#endif
