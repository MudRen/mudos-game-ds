#include <ansi2.h>
#include <weapon.h>
inherit FORK;
void create()
{
        set_name(HIG"�����j"NOR,({"longwind pike","pike"}) );
        set("long",
        "�����j�A���@�몺���j���T�ءA�]���S���@�w����O�O�����_�Ӫ��C\n�ҥH�L�W�ꪺ�x�H�L�@���H����ϥΪ����j���a�C\n");
          set_weight(7000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","��");
        set("value",2500);
        set("volume",4);
        set("material","iron");
        init_fork(30);
   	}
        setup();
}

