#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{



set("short", HIY"�T�a"NOR);
set("long", @LONG
�o�̬O�ⶳ�x���T�a�A���\�h�ⶳ���̤l�b����ݦu�ۡA�����O�n����        
���b�̭����}�ٹ��X�Ӿx�ơAť�ݦu���̤l���A�̭����\�h�r�V�b���Ať��
�O�̭����}�ٹ������s�y�X�ӤF���A�o�r�V�����L��A���Ǥ�V�n���X�x
���Z�����W���M�|�Ӭݦu�E        
LONG

  );      

 set("no_clean_up", 0);

 set("exits", ([ /* sizeof() == 1 */

 "south" : __DIR__"a2",
]));

       
set("objects",([

   "/u/k/kakasi/npc/b1" : 1,
]) );

        set("outdoors", "land");



        setup();

        replace_program(ROOM);

}


     




