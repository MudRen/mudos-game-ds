#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("[0;1;35m�[1mL[1m�[1m�[1;37m�[1m�[1m�[1mF[0m", ({ "smile elf","smile","elf" }) );
        set_weight(11000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","
�o�O�@��륩����u�����A��A�J�ӧ⪱���ɭԡA
���Gı�o�o���b��A�L���ۡC"HIC"[2003�~�C�i��������]
\n"NOR);
                set("unit", "��");
                set("material", "gold");
                set("no_sell",1);
               //set("no_drop",1);
               //set("no_auc",1);
               //set("no_get",1);
              // set("no_give",1);   
                set("value",4800);
        }
              setup();
}
int query_autoload() { return 1; }

