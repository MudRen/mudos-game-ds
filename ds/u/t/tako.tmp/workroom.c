#include <ansi.h>
inherit ROOM;
void create()
{
                 set("short",HIY"���B��"NOR);

                 set("long", 
      HIC"�o�O�@�a�R���w��,����,�ּ֪��@�a��,�̭��C�ӤH�����۱���,\n"NOR HIG"�A�C�C�����i�o�a��,�A�ϩ��]�P��F�o���ɪ���,�A�ݨ���\n"NOR
      HIB"�`�O���@�ӤH,���a�۲H�H�����N,�A�n���Q�o�l�ޤF,�g�L��ť�~\n"NOR     HIR"���D,���O���ҤH,�o�`�O���a�L������:\n"NOR
      HIW"�A�n��..�w��Ө�ڸ�ڦѤ������B��^^\n"NOR

          );

        set("light", 1);

set("exits", ([  /* sizeof() ==  8  */
"sex" :  "/u/s/sexking/workroom" ,
"com" :  "/u/c/cominging/workroom" ,
"past" : "/open/world1/tmr/area/hotel" ,
"lin" : "/u/l/linjack/workroom" ,
"wilfred" : "/u/w/wilfred/workroom" ,
"bread" : "/u/t/tako/ovenroom" , 
"pooding" : "/u/t/tako/pooding room" ,
"area" : "/u/t/tako/area/room~1.c" ,
])); 
set("objects", ([ /* sizeof() == 2 */
  "/u/t/tako/poo-ding.c" : 1, 
  "/u/t/tako/shelf.c" : 1, ]));
set("valid_startroom", 1);

setup(); 
call_other("/obj/board/tako_b.c", "???");

}



void init()

{
     object me=this_player();

     me->set("startroom","/u/t/tako/workroom");

                 } 



