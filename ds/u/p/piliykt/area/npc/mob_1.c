inherit NPC;

void create()
{
        set_name("農夫",({"farmer"}) );
        set("long",
"一位正彎腰、赤腳站在田裡插秧的農夫，瞧他辛苦揮汗的背影，令人\n"
"不由地打從心裡感謝農夫終年的辛勞。\n"
        );
        set("age",35);
        set("level",6);
        set("race","人類");
        set("attitude", "peaceful");
        set("unarmed",22);
        set("parry",12);
        set("chat_chance",8);
        set("chat_msg",({
        "農夫高聲吟道：「鋤荷日當午　∼∼」。\n",
        "農夫高聲吟道：「汗滴禾下土　∼∼」。\n",
        (:command("sweat"):),
        "農夫高聲吟道：「誰知盤中飧　∼∼」。\n",
        "農夫高聲吟道：「粒粒皆辛苦　∼∼」。\n",
        }) );
        set_skill("unarmed",25);
        setup();                
        add_money("coin",300);
}

