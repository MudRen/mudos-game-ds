inherit NPC;

void create()
{
        set_name("�j�Ѫ�", ({"big tiger","tiger"}) );
        set("long", "�@���D�`�j���Ѫ�A���b�o�̪������ݵۧA�C\n");
        set("unit","��");
        set("race", "beast");
        set("limbs", ({ "�Y��", "����", "�I��", "��}", "�{�l" })); //���𳡦�
        set("verbs", ({ "crash","claw" })); //�������A��hoof��crash�rbite��claw��poke
        set("age", 1);
        set("level",3);
        set_temp("apply/hit",-10);      //�z�ƩR���v
        set_temp("apply/dodge",-10);    //�z�ư{���v
        set("chat_chance",1);
        set("chat_msg",({
                //(: this_object(), "random_move" :),
                "�j�Ѫ�~~~�q~~~~���@����ۧA�j�s�C\n",
        }));

        setup();
         }
