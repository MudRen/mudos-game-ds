#include <ansi.h>
inherit NPC;
void create()
{
 set_name("���˪��X�D",({"leader",}));
 set("long",@LONG
�@�Ӥs�몺�X�D, �L�ݨӨ��ˤ���.....
LONG
    );
 set("attitude", "aggressive");
 set("age",40);
 set("gender","�k��");
 set("level",1);
 set("hp",1);
 set("con",1);
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
 carry_object(__DIR__"obj/flag");

}
