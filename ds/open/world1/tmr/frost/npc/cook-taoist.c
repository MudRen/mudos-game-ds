inherit NPC;

void create()
{
        set_name("伙食道人",({"cook taoist","taoist"}) );
        set("long",@LONG
一個在寒澈道觀裡負責伙食的道人，雖然已近古俙之年，但還是老當
益壯、耳聰目明的樣子，該是因為在道觀修身養性，與世無爭的心境影響
下，才能有這種老而不廢的健康身體。
LONG
);
        set("age",70);
        set("race","人類");
        set("level",15);
        set("attitude", "peaceful");
        set("gender", "男性" );
        set("title","寒澈道");
        set("chat_chance",10);
        set("chat_msg",({
                "伙食道人喃喃自語道：「三十五年前那怪事還真是令人難以忘記啊..」。\n",
                "伙食道人俐落地拿了把菜刀，兩三下就切好一鍋大白菜了。\n",
                "伙食道人從一旁的大水桶裡舀起了水，迅速地沖洗碗筷。\n",
        }) );

        set_skill("parry",40);
        set_skill("dodge",40);
        set_skill("unarmed",40);
        set("inquiry", ([
                "怪事": "嗯....那時貧道正當壯年，記的非常清楚，是在觀內禪室遇到的。",
                "禪室": "那時貧道半夜睡不著，想說來去禪室修鍊，怎知甫一踏進，即聞到濃厚的血腥味，就不醒人事了。",
                "血腥味": "現在想起來，仍然記得是種很噁心而恐怖的味道。",
        ]) );
        setup();
        carry_object(__DIR__"eq/shoe")->wear();
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");

}

