#include <ansi.h>
inherit NPC;
mapping *combat_action = ({
        ([      "action":              "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+HIY+"���]�Z"+NOR+""+CYN+"�j"+NOR+"�@�D�����{�L$n��$l!",

                "attact_type":  "sou",  // �]�w�ޯ઺��������
                                        // ������ �ͪ�(bio) �~��(bar)
                                        // �]�k(wit)���F(sou)���(tec)
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
        ([      "action":               "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+MAG+"���\\�Z"+NOR+""+CYN+"�j"+NOR+"�@�D�����{�L$n��$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
        ([      "action":               "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+HIR+"�}���Z"+NOR+""+CYN+"�j"+NOR+"�@�D�����{�L$n��$l!",

                "attact_type":  "sou",
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
    ([  "action":       "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+HIC+"�᧯�Z"+NOR+""+CYN+"�j"+NOR+"�@�D�ť��{�L$n��$l!",
                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
    ([  "action":       "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+HIM+"����Z"+NOR+""+CYN+"�j"+NOR+"�@�D����{�L$n ��$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
    ([  "action":       "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+GRN+"�C��Z"+NOR+""+CYN+"�j"+NOR+"�@�D����{�L$n��$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
    ([  "action":      "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+HIW+"�����Z"+NOR+""+CYN+"�j"+NOR+"�@�D�ե��{�L$n��$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
    ([  "action":      "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+WHT+"�|�ƳZ"+NOR+""+CYN+"�j"+NOR+"�@�D�ǥ��{�L$n��$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
    ([  "action":      "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+YEL+"�a�g�Z"+NOR+""+CYN+"�j"+NOR+"�@�D�ť��{�L$n��$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
});

void create()
{
        set_name(MAG"�_���~"NOR,({"chini"}) );
        set("long",@LONG
�o�O�ǻ��������~�_���~�A�ڻ�����ӬO��u�Q�U�j�s�a�Ϫ���
�ӡA���b��������l�������Q�@�T
���_�o�X�H�𪺩_�ǫ����һ�
�b�A�̫�b�����p�W���ܦ��{�b���_���~....���O�o�Ӷǻ��I���
�G�٦��@�Ө����o�H�¹��s�b...
LONG
);
        set("title",HIR"�u�Q�U���~�v"NOR);
        set("age",1200+random(50));
        set("level",60);
        set("gender","����");
 set("attitude", "peaceful");
        set("chat_chance", 13);
        set("chat_msg",({ 
        "�_���~���M�Q�@�Ѥ����ҥ]��A�h�W���j�q�@�n.....�C\n",
        }));
        set("limbs", ({ "�Y��", "����", "�e��", "���", "����","���l" }) );
        set("verbs", ({ "bite", "claw" }) );
      set("Merits/bar",9);
      set("Merits/sou",9);
      set("str",155);
      set("int",50);
          set("addition_armor",100);

    set("Merits/wit",3);
        set("addition_damage",50);
      set("no_busy",1);
        add("apply/hit",50);
        setup();
        set("actions", (: call_other, __FILE__, "query_action" :));
    carry_object(__DIR__"eq/chini_wrist")->wear();
    carry_object(__DIR__"eq/chini_boots")->wear();
}

mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

void die()
{
        object ob;
        
        if( !ob = query_temp("last_damage_from") ) ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }
        message("world:world1:vision",

           HIW"\n�i�Q�U�j�s�j"+HIW"�Q�U�ͦ��L�b�U���L�h����U�U, �A�ױN�_���~���F�v�^�Ѭ�!\n\n"+NOR,users());
            ob->add("popularity",5); //�n��
        ::die();
        return;
}

int accept_object(object who,object ob)
{
           int i;
                object obj,me,g;
                obj=this_object();
                me=this_player();
                if(ob->id("ice stone"))
                {
            message_vision("�_���~���M�@�}�ǲ����ݰ�....! \n",who);
       set("Merits/bar",5);
        set("Merits/sou",5);
        set("level",60);
         message_vision(HIC"�@�}�ť��{�L, �A�����䩿�M�h�F�@�ӵo�����F��! \n"NOR,who);
       message("world:world1:vision",
           MAG"\n�i�Q�U�j�s�j"+HIR"�H�����s�i�J�_���~���F�A�Q�U���~����d���I�I\n\n"+NOR,users());
       g=new(__DIR__"maigu.c");
        g->move("/u/f/faceoff/area/sky/ten38.c");
       g=new(__DIR__"wo.c");
        g->move("/u/f/faceoff/area/sky/ten50.c");
        for(i=0;i<=5;i++)
        {
                       g=new(__DIR__"ghost.c");
                g->move("/open/world1/faceoff/sky/ten9");
                       g=new(__DIR__"ghost.c");
                g->move("/open/world1/faceoff/sky/ten25");
                       g=new(__DIR__"ghost.c");
                g->move("/open/world1/faceoff/sky/ten44");

        }
  for(i=0;i<=2;i++)
        {
                       g=new(__DIR__"ghost2.c");
                g->move("/open/world1/faceoff/sky/ten2");
                       g=new(__DIR__"ghost2.c");
                g->move("/open/world1/faceoff/sky/ten7");
                       g=new(__DIR__"ghost2.c");
                g->move("/open/world1/faceoff/sky/ten4");

        }

            destruct(ob);
            return 1;
                }
     else
          {
         message_vision("�_���~�j�q�@�n�A�N"+ob->query("name")+"�����R��! \n",who);
            command("kill "+who->query("id")+"");
            destruct(ob);
            return 1; 
          }

}
