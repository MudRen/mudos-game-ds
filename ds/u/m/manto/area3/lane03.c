#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR"���D"NOR);
        set("long", @LONG
�o�����t�����D�b�s�������驵���A�����q����B�C�e�����D���V��
�V�t�A�A�֭n�ݤ����F��F�C�o�̪Ů�ÿB�A�٧����ۤ@�Ѩ�󪺨��D�A
�A�@���L�ӫKı�o�Y���o�w�A���O���r�F�C
LONG);                
        set("exits", ([
              "west" : __DIR__"lane04",
              "east" : __FILE__,
              "north" : __FILE__,
              "south" : __DIR__"lane02",
        ]));
        setup(); 
}

void init()
{    
  	object me = this_player();
     	if (random(me->query_skill("anti_poison")) <50 && me->query_con() < 50){ 
        	tell_object(me, HIB "�A���M�P��I�l�@��A��ӬO�o�̪��Ů�ÿB�B�y�q���Z�C\n" NOR );      
             	tell_room(environment(me), me->name()+"��M�y���ܱo�������ݡA�ò`�`�a�l�F�f��C\n" NOR,({ me }));
             	me->receive_damage("hp", 60);
             	me->receive_damage("mp", 50);
             	me->receive_damage("ap", 20);
             	}               
}
