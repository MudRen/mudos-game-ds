//�x�����eq 200.10.14 by Promise@DS
#include <armor.h>
#include <ansi.h>
inherit SHIELD; 
void create()
{
        set_name(HIW"�y"HIB"�t"HIM"��"HIY"��"HIW"[0;1m�[1mz[0m"NOR,({"holy-light shield","holy","light","shield","h","l","s"}) );
        set("long","�۶ǳo�󪺸t�ެ��jù���ԯ�--�����ͫe�ҥ�,��ӥL�N�h�@�e,��@�����O�q�ʦL�b�o�ޤW
    \n"NOR);
        set_weight(3500);
        if ( clonep() )
                set_default_object(__FILE__);
         else {
         set("volume",3);
         set("material","silver");
         set("unit", "��" );
         set("no_sell",1); 
         set("no_give",1);
         set("no_auc",1);
         set("no_drop",1);         }
        set("armor_prop/armor", 1);
   set("wear_msg","[0;1;36m�[1mA[1;37m�[1m|[1m�[1m_[1;32m�[1my[1;34m�[1mt[1;33m�[1m�[1;35m�[1m�[1;32m�[1mz[1;37m�[1m�[1m�[1m�[1;33;43m�[1m�[1m�[1m~[1;37;41m�[1m|[1m�[1mg[1;40m�[1mA[1m�[1m@[1m�[1mD[1;33m�[1m�[1m�[1m�[1;37m�[1mq[1;35m�[1m�[1;37m�[1m�[1m�[1m�[1m�[1mX[1m�[1mA[1m�[1mu[1m�[1m�[1m�[1mA[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1mo[1m�[1mX[1m�[1m�[0;1;5;33m�[1;5m�[1;5m�[1;5mt[1;5m�[1;5m�[1;5m�[1;5m~[0;1;37m�[1mA[1m�[1m�[1m�[1m�[1m�[1mb[1m�[1m|[1m�[1mP[1;30m�[0m[0;1;30mO[1m�[1m@[1;37m�[1m�[1m�[1mA[0m\n"NOR);
       set("unequip_msg"[0;1;36m�[1mA[1;37m�[1m�[1m�[1mU[1;32m�[1my[1;34m�[1mt[1;33m�[1m�[1;35m�[1m�[1;32m�[1mz[1;37m�[1m�[1m�[1mW[1m�[1m�[1;33;43m�[1m�[1m�[1m~[1;37;40m�[1mA[1m�[1m�[1m�[1m�[1;32m�[1mL[1m�[1m�[1;37m�[1m�[1;33m�[1m�[1m�[1mI[1;37m�[1mA[1m�[1m�[1m�[1mL[1;36m�[1m�[1m�[1md[1;37m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[0m
,\n"NOR);
        setup();
}

int query_autoload() { return 1; }

void init()
{
        if(!this_object()->query_light()) this_object()->start_light(1);
}

