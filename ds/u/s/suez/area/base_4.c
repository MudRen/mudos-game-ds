#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", CYN"�����a"NOR);
	set("long",@LONG
�A���Ǫ��g���W��F�u�����a�v�T�Ӧr�A�|�P��²��������ΡN��H
�H�γ\�h�ԾĽm�\���K�P���̤l�C���L�ݱo�X�ӡA�S���v�����ɪ��L�̡A
�Z�\�i�i��b�����C���O�{�u�����o�ϧA��L�̪o�M�ͷq�C
LONG
       );
	set("exits", ([ /* sizeof() == 1 */
                   "north" : __DIR__"base_5",
               ]));
            set("objects",([
              __DIR__"npc/apprentice1" : 2,
           __DIR__"npc/apprentice2" : 2,
              ]) );
        set("light",1);
	set("no_clean_up", 0);
	setup();
}