#include <ansi.h>

inherit ITEM;
void create()
{
        set_name(HIW"��"HIC"�~"HIW"��"NOR, ({ "alien-beast stone", "stone" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                 set("long",
        "�@�ӥb��O�s�b��O�ꪺ�ۨ�A�W���g�ۥj��A���G�O���M�`\n"
        "�����A�]�\\�ӧ�H½Ķ�ݬݤW���o�j��A�ӥB�s���J��������\n"
        "�@���p�����A�]�\\�i�H�N����}\n");
                set("unit", "��");
                set("value",100);                
        }
        setup();
}




