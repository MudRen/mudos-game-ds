inherit NPC;
void create()
{
        set_name("�^��",({ "beggar" }));
        set("long","�@�ӧ��b�����B�n���Y���H�C\n");
        set("level", 5);
        set_skill("unarmed", 30);
        set_skill("dodge", 20);
        set("age",45);
        set("chat_chance", 5);
        set("chat_msg", ({
  "�^�����G ��~~�{�l�n�j�C\n",
  "�^�����G �n�ߪ��H,�i���i�H���ڤ@���C�Y.\n"
  "�^����~~���ĤF�@�f��!!.\n"  
}) );
        setup();
        
}


