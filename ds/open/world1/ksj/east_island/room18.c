#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
 set("short","�K�E");
 set("long",@LONG
�@���¶�żż���K�E�A�@�Ǫ�����Ƶۥ����Ϊ��M�F�ά���A��
������l�ǧ��ۤ@�ӧ��Ӫ��K�K�A���b�e�۩_�Ǫ��ϧΡA��l�W�٩�
�ۤ@���U�l��@���W�MŲ�A�Ψӷ��K�����l�èS���ɤ��C
LONG
    );
   set("exits",([ 
       "east":__DIR__"room13",
   ]));

   set("no_clean_up",0);
   set("light",1);
   set("item_desc", ([
       "�U�l" : "�@���u���ѥ֪��U�l�A�W���g��"HIY"�i�_�Ҥ�ű���j"NOR"�гƫe�D��  �ۡC\n",
       "�W�MŲ" : "�g�ۦW�M�����и�ϮסA�A�J��½�ݡA�̭��O���F�H�U�W�M�G\n\n"
                 +"\t    "MAG"���M"HIR"�D"HIC"���B"NOR"(Murasame katana)\n"
                 +"\t    "HIW"�W�M"HIR"�D"HIC"���"NOR"(Kote katana)\n"
                 +"\t    "HIW"�ǤѰ�@"HIR"�D"HIC"�p�Q�Y�ӤM"NOR"(Shouugan katana)\n"
                 +"\t    "MAG"�c���M"HIR"�D"NOR""GRN"����"NOR"(Hide-bone katana)\n"
                 +"\t    "HIW"�ƫe����"NOR"(Bizen-chousen katana)\n"
                 +"\t    "HIY"��"HIW"�@��r"NOR"(Kiku-ichimonji katana)\n"
                 +"\t    "HIM"��ûR"NOR"(Sakura-ranbu katana)\n\n",
      ]));
   set("objects",([
      __DIR__"npc/bizen-gou":1,
      ]));
   setup();
}            
