inherit NPC;

void create()
{
        set_name("�A��",({"farmer"}) );
        set("long",
"�@�쥿�s�y�B���}���b�и̴������A�ҡA�@�L���W�������I�v�A�O�H\n"
"���Ѧa���q�߸̷P�¹A�Ҳצ~�����ҡC\n"
        );
        set("age",35);
        set("level",6);
        set("race","�H��");
        set("attitude", "peaceful");
        set("unarmed",22);
        set("parry",12);
        set("chat_chance",8);
        set("chat_msg",({
        "�A�Ұ��n�u�D�G�u�S�����ȡ@���v�C\n",
        "�A�Ұ��n�u�D�G�u���w�ݤU�g�@���v�C\n",
        (:command("sweat"):),
        "�A�Ұ��n�u�D�G�u�֪��L�����@���v�C\n",
        "�A�Ұ��n�u�D�G�u�ɲɬҨ��W�@���v�C\n",
        }) );
        set_skill("unarmed",25);
        setup();                
        add_money("coin",300);
}

