inherit NPC;
void create()
{
        set_name("Ĭ�|�J", ({ "su luke", "su", "luke"}));
        set("gender", "�k��");
        set("age", 45);
        set("level", 30);
        set("title","���ħJ�i�h");
        set("long", "�L�N�O���ħJ�Ĥ@�i�hĬ�|�J�C\n");
        set("attitude", "heroism");
        setup();
        carry_object(__DIR__"obj/wandao")->wield();
        carry_object(__DIR__"obj/yangao")->wear();
        carry_object(__DIR__"obj/jiunang");
}