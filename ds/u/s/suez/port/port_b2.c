#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","�a�U���D");
	set("long",@LONG
�X�������Q���@�ӴN�԰հ԰ժ����F�_�ӡA�I�R��Ӫ��]�p���o���t
���a���W�K�F�ǳ\�޲�����^�A���w�����n�������a�j���ۡA�ۤv���}�B
�n�]�b�Ů𤤨Ӧ^�L�ۡA���H�Pı�n��������F��b�·t���s���ۧA�C
LONG 
);	
	set("light",0);
	set("exits",([
	    "north":__DIR__"port_b1",
	    "east":__DIR__"port_b4",
	    "south":__DIR__"port_b3"
		]));
	set("world","world1");
	set("objects",([
	    __DIR__"npc/bat":2,
		]));

	setup();

}
int valid_leave(object me, string dir)
{
	int temp = me->query_temp("police");
	if( me->query_temp("police_area")==1 && userp(me)) 
	{	
		temp++;
		me->set_temp("police",temp);
	}
        return ::valid_leave(me, dir);
}
