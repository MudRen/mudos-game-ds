#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"���D"NOR);
        set("long", @LONG
�o�����t�����D�b�s�������驵���A�����q����B�C�o�̪��۾��D�`
����A�ݨӪ��񦳤����C
LONG);
        set("objects", ([
                    __DIR__"npc/boa" : 1,
        ]));
        set("exits", ([
              "westdown" : __DIR__"lane03",
              "east" : __DIR__"lane01",
        ]));
        setup(); 
}

void init()
{    
  	object me = this_player();
     	if (random(me->query_skill("anti_poison")) <50 && me->query_con() < 50){ 
        	tell_object(me, HIB "�A���M�P��I�l�@��A��ӬO�o�̪��Ů�ÿB�B�y�q���Z�C\n" NOR );      
             	tell_room(environment(me), me->name()+"��M�y���ܱo�������ݡA�ò`�`�a�l�F�f��C\n" NOR,({ me }));
             	me->receive_damage("hp", 50);
             	me->receive_damage("mp", 50);
             	me->receive_damage("ap", 50);
             	}           
}
