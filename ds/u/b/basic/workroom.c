#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
 set("short", HIY"�p��"HIM"�ڹ�"NOR);

 set("long",
            HIY"\n\t�p���A�O���ΧO�H�h�ޤ~�s�p���C\n"
            HIC  "\t�ۦb�A�O�����~�ɪ������~�s�ۦb�C\n"
            HIM  "\t�ڡA�O�Ϊ�����´�u�s´�_�Ӫ��C \n"
            HIW  "\t�۹ҡA�O���X�j�۵M���@����...\n\n"NOR
            );
       set("objects",([
          "/u/b/basic/item/box" :1,

]));
      set("exits", ([ /* sizeof() == 7*/
            "down" :"/u/a/acme/workroom",
            "luky" :"/u/l/luky/workroom",
            "tmr"  :"/u/t/tmr/workroom" ,
            "cominging":"/u/c/cominging/workroom",
            "wizard" :"/d/wiz/hall1",
            "kelly" :"/u/c/cutekelly/workroom",
            "sex" :"/u/s/sexking/workroom",

]));
set("light",1);
      set("valid_startroom", 1);
         setup();
call_other("/obj/board/basic_b", "???");
}
