#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIM "�L��" NOR ,({ "zombie" }) );
         set("level",20);
        set("age", 200);
        set("long", "�o�O�@��w���h�G�ʦh�~�����͡A���å��G��A�Ҽ˥O�H�@���C\n"
);
      set("con",15);
         set("exp",1000);
       set_skill("dodge",50);
        set_skill("unarmed",50);
        set_skill("parry",50);
        set("unit","��");
      set("race","�H��");
             set("attitude","killer");

        set("chat_chance", 5);
         set("chat_msg",({
          "�L�ͱq�f���o�X�G�u���������v���n���C\n"
     }));
        set("chat_msg_combat", ({
                "�L�ͪ��y�W�}�l�j�ˡM�@�}���z�M�o�g���a�j�s�C\n",
                "�L�ͤ����߱i�M�r�������M�S�X�u�񪺯��e�C\n",
        }) );

        setup();
}
