#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","���Y��");

 set("long",@LONG
�o�O�@���Υ��Y���y����, ���M���O���Y����, ��
�O���_�ӫo�񥭦a�٭n��, �A�ݬݥ|�P, �o�{���䦳�@
�ӥ��۸O(sign), �W���٦��@�ǧA�q�ӨS���ݹL����,
���Y�����F�詵���X�h�C

LONG
    );
 set("item_desc",([
        "sign":"�A�³o�۸O�W�ݤF��  "HIR"��
                    ��"NOR"        
�A�߷Q�ש��F!     "HIR"��\n"NOR
     ]));
 set("exits",(["east":__DIR__"bird12",
               "southdown":__DIR__"bird10",
     ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
