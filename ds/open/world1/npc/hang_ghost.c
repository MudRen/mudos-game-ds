inherit NPC;

void create()
{
        set_name("�Q����", ({ "hanged ghost","ghost" }) );
        set("race","human");
        set("gender", "�k��");
        set("level",17);
        set("attitude","aggressive");
        set("age",180);
        set("evil",5);
        set("long",@LONG
�W�Q�Ӧ�������A���������Y��o�S�����A�W�Q�ɪ�÷�l
�A�����b��l�W�A���¦⪺�~���b÷�l�P����«D�`����C
LONG
);
        set("chat_chance",10); 
        set("chat_msg",({
                "�Q�����������Y, �Q���ƻ�o�����X�C\n",
                "�Q�����δc�����������E���ۧA�C\n",
        }) );
        setup(); 
}

