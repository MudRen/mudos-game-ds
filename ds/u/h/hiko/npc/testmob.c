#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�����~",({"test monster", "test","monster" }) );
        set("long",@LONG
      TEST �Ϊ����~......���@��
LONG
);
        set("title","����쩳");
        set("limbs", ({
                "�Y��", "�V��", "�ݤf", "���", "�y��", "����", "�j�L","����",
        }) );
        set("age",500+random(99));
        set("level",70);
        set("hp",999999);
        set("max_hp",999999);
        set("mp",999999);
        set("max_mp",999999);
        set("ap",999999);
        set("max_ap",999999);        set("dex",100);
        set("str",100);
        set("con",100);
        set("int",100);
        set("gender","����");
        set("race","monster");
        setup();
}
 

