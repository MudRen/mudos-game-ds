inherit NPC;
void create()
{
        set_name("蘇魯克", ({ "su luke", "su", "luke"}));
        set("gender", "男性");
        set("age", 45);
        set("level", 30);
        set("title","哈薩克勇士");
        set("long", "他就是哈薩克第一勇士蘇魯克。\n");
        set("attitude", "heroism");
        setup();
        carry_object(__DIR__"obj/wandao")->wield();
        carry_object(__DIR__"obj/yangao")->wear();
        carry_object(__DIR__"obj/jiunang");
}