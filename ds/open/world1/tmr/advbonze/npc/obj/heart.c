// An example doll.c
// "undead_item" ��name�ФŶå�.

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIG"�p�Ӧ��"NOR,({"rulaifo heart","heart","undead_item"}));
                set("long",
"�@�����o���A����~���p�Ӧ�ߡA�j�p�H���A�����z�A\n"
"�~����ƵL��ү�A���G�٥��w�w���ʵۡC"
                );

        set_weight(100);
                set("value",0);
                  set("no_put",1);
                  set("no_get",1);
                set("unit","��");
                  set("undead_msg",HIW"\n\t�N�b$N��Ŧ������ʡA�N�n�]�U�̫�@�f��ɡA$N���W��$n"HIW"��M�ĤJ$N���ݵĤ��I�I\n"NOR);
        setup();
}


