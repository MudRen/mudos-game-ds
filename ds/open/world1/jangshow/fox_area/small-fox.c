inherit NPC;

void create()
{
        set_name("�p���W",({"small fox","fox"}));
        set("long","�@�ئb�ⶳ�x�`�������W�C\n");
        set("gender","��");
        set("attitude", "peaceful");
        set("age",3);
       set("level",15);
        set("race","beast");
        set("chat_chance",7);
        set("chat_msg",({
          "�p���W���F�U�ӡA��F���o�A�ˤl�Q���i�R�C\n", 
        (: random_move :),
         }) );
        setup();
}

