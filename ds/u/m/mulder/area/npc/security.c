inherit NPC;

void create()
{
        set_name("銀行保安", ({ "security" }) );
        set("long",
        "一個看來保護銀行安危的青年，長得虎背熊腰、孔武有力的樣子。\n"
        );
        set("class","fighter");
        set("gender","男性");
        set("age",23);
        set("level",15);
        set_skill("parry", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        setup();
      //add_money("thousand-cash",2); 沒有這個東西.
        }
