#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name( HIY"��᪺�p�h�Q"NOR, ({ "flower girl","girl","seller"}));
        set("long", "�@�ӥi�R���p�h�Q�A��̩�ۤ@�Ӫ��x�A�̭��˺��F�h���h������C\n\n"
        );
        set("level",3);
        set("title","�p�c");
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 15);
        set("evil",-20);                //���c�� 20 (�������c, �t���})
        set("attitude", "peaceful");   //�ũM�� NPC�C
        set("talk_reply","�Q�R��ܡH�i�H�άݬݧڪ����x�A���ܦh���(list)�C");

        set("sell_list",([   
         __DIR__"obj/hyacinth"    : 10,
        ]));

//set("chat_chance", 3 );
// set("chat_msg", ({
//"���j�o��������: �j����, �n���n�R�I�F��<take>��? �ڽ檺�F��<show>�O����̫K�y����!\n",
//(:command("dance master"):),
//(:command("coffee wang"):),
//}) );

set("inquiry/flower", @LONG
   ��̥i�R�F�A�o�̪��H���R���C
LONG );

      setup();
      add_money("coin", 150);
      carry_object(__DIR__"item/bag");
}

void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy","buy");
}
