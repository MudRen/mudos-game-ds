// Jay 3/17/96
inherit NPC;
string ask_li();
void create()
{
        set_name("計老人", ({ "ji oldman", "ji", "oldman"}));
        set("gender", "男性");
        set("age", 83);
        set("long", "滿頭白髮，竟無一根是黑的，身材甚是高大，只是弓腰曲背，臉上全是皺紋，衰老已極。\n");
        set("attitude", "friendly");
        set("level", 15);
        set("inquiry", ([
            "哈薩克人" : "哈薩克人最愛喝又香又烈的美酒。\n",
            "華輝" : "誰？我不知道這個人。\n",
        ]) );
        setup();
        carry_object(__DIR__"obj/bishou")->wield();
        carry_object(__DIR__"obj/yangao")->wear();
        carry_object(__DIR__"obj/rousisuo");
}
