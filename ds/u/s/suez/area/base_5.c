#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIY"�K�P��"NOR);
	set("long",@LONG 
���F�|������W��������A�o�̴N�u�������g�ۡu�K�P���v�����B�A
�M�q����L�ж����q�D�Ӥw�C���M²���A�o�����������b�b�A�a�W�H�ӥ�
�Q���A����]���W������զ�C���O�����O�Ӥg�ǡA���W�N�Ѫ�O�W����
�٬O�|���U�ǳ\�g�h�C
LONG
       );
	set("exits", ([ /* sizeof() == 1 */
                   "east" : __DIR__"base_1",
                   "west" : __DIR__"base_2",
                   "north" : __DIR__"base_3",
                   "south" : __DIR__"base_4",
               ]));
        set("light",1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}