#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�h�A",({"farmer",}));
 set("long",@LONG
�@�ӤQ�U�j�s���`�����A��.
LONG
    );
 set("attitude", "peaceful");
 set("age",40);
 set("gender","�k��");
 set("level",15);
 set("chat_chance",10);
set("chat_msg", ({"�h�A�۹D:�d���^�����y�y,�Э��q�Ӥ��X�Y. \n",
                  "�h�A�۹D:�Q�������E����,�b�~���H�b�~�T.\n",
}));
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
}
