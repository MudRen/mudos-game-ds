// human.c
#pragma save_binary
#include <race.h>

inherit F_DBASE;

mapping *combat_action = ({
        ([      "action":               "$N揮拳攻擊$n的$l",
                "attact_type":  "bar",  // 設定技能的攻擊種類
                                        // 種類有 生物(bio) 獸性(bar)
                                        // 魔法(wit)心靈(sou)科技(tec)
                "damage_type":  "瘀傷",
        ]),
        ([      "action":               "$N往$n的$l一抓",
                "attact_type":  "bar",
                "damage_type":  "抓傷",
        ]),
        ([      "action":               "$N往$n的$l狠狠地踢了一腳",
                "attact_type":  "bar",
                "damage_type":  "瘀傷",
        ]),
        ([      "action":               "$N提起拳頭往$n的$l捶去",
                "attact_type":  "bar",
                "damage_type":  "瘀傷",
        ]),
        ([      "action":               "$N對準$n的$l用力揮出一拳",
                "attact_type":  "bar",
                "damage_type":  "瘀傷",
        ]),
});

void create()
{
        seteuid(getuid());
        set("can_speak", 1);

        set("limbs", ({ "head","body","right_arm","left_arm","right_leg","left_leg" }) );
        set("limbs_effect",([
        "int" : ({"head"}),
        "con" : ({"body"}),
        "dex" : ({"right_leg","left_leg"}),
        "str" : ({"right_arm","left_arm"}),
        "skill" : ({"head"}),
        ]));
}

void setup_attribute(object ob)
{
        mapping my;

        my = ob->query_entire_dbase();
        if( undefinedp(my["unit"]) ) my["unit"] = "位";
        if( undefinedp(my["gender"]) ) my["gender"] = "男性";
        if( undefinedp(my["attitude"]) ) my["attitude"] = "peaceful";
        ob->set("default_actions", (: call_other, __FILE__, "query_action" :));
        if( undefinedp(my["heart_beat_rate"]) ) my["heart_beat_rate"] = 6;
        if( undefinedp(my["age"]) ) my["age"] = random(30) + 15;
        if( undefinedp(my["level"])) my["level"] = random(5)+1;
        if( undefinedp(my["guild_gifts"])) my["guild_gifts"] = ({5,5,5,5});
        if( undefinedp(my["str"]) ) my["str"] = (my["level"]*(10+my["guild_gifts"][0]))/8+random(my["level"]/5);
        if( undefinedp(my["con"]) ) my["con"] = (my["level"]*(10+my["guild_gifts"][1]))/8+random(my["level"]/5);
        if( undefinedp(my["int"]) ) my["int"] = (my["level"]*(10+my["guild_gifts"][2]))/10+random(my["level"]/5);
        if( undefinedp(my["dex"]) ) my["dex"] = (my["level"]*(10+my["guild_gifts"][3]))/10+random(my["level"]/5);
        if( undefinedp(my["volume"]) ) my["volume"] = 7+my["con"]/20;
        if( undefinedp(my["Merits"])) // 設定內在素質
        {
                my["Merits"]=([
                                "bio": (my["con"]+my["dex"])/30,
                                "bar": (my["con"]+my["str"])/30,
                                "wit": (my["int"]+my["dex"])/30,
                                "sou": (my["int"]+my["str"])/30,
                                "tec": (my["int"]+my["dex"])/30,
                                ]);
        }
        else
        {
                if( undefinedp(my["Merits"]["bio"])) my["Merits"]["bio"]=(my["con"]+my["dex"])/30;
                if( undefinedp(my["Merits"]["bar"])) my["Merits"]["bar"]=(my["con"]+my["str"])/30;
                if( undefinedp(my["Merits"]["wit"])) my["Merits"]["wit"]=(my["int"]+my["dex"])/30;
                if( undefinedp(my["Merits"]["sou"])) my["Merits"]["sou"]=(my["int"]+my["str"])/30;
                 if( undefinedp(my["Merits"]["tec"])) my["Merits"]["tec"]=(my["int"]+my["con"])/30;
        }

        if( undefinedp(my["evil"]) ) my["evil"] = -random(my["level"])-1;
        if( undefinedp(my["exp"]) )
        {
                if( undefinedp(my["exp_point"]) ) my["exp_point"] = 0;
                my["exp"] = my["level"]*60 + my["level"]*my["level"]*(7+my["exp_point"])+random(my["level"]*60);
                if(my["level"]>25) my["exp"]+=my["level"]*my["level"]*4;
        }
        if( userp(ob) || undefinedp(my["max_hp"]) )
        {
           int q_con = ob->query_con(); 
           if(userp(ob))
           {
                my["max_hp"] = 40 + ( q_con * 20 ) ;
           } else
           {
                 my["max_hp"] = my["level"]*my["level"]*3;
                 my["max_hp"] += q_con * 30;
           }
        }
        if( userp(ob) || undefinedp(my["max_mp"]) ) {
           if(userp(ob))
           {
                int q_int = ob->query_int();
                my["max_mp"] =  30 + q_int * 15;
           } else
           {

                int q_int = ob->query_int();
                my["max_mp"] = my["level"]*20;
                my["max_mp"] +=  q_int * 20 ;
           }
        }
        if( userp(ob) || undefinedp(my["max_ap"]) ) {
           if(userp(ob))
           {
                int q_con = ob->query_con();
                my["max_ap"] =  30 + q_con * 15 ;
           } else
           {
                int q_con = ob->query_con();
                my["max_ap"] = my["level"]*20;
                my["max_ap"] +=  q_con * 20 ;
           }
        }
        if( undefinedp(my["hp"]) ) my["hp"] = my["max_hp"] ;
        if( undefinedp(my["mp"]) ) my["mp"] = my["max_mp"] ;
        if( undefinedp(my["ap"]) ) my["ap"] = my["max_ap"] ;
        if(!userp(ob))
        {
                if( undefinedp(my["combat_exp"]) ) my["combat_exp"] = my["level"]*(1+my["exp_point"])*500;
                if( undefinedp(my["addition_armor"]) ) my["addition_armor"]=my["level"]*3/2;
                if( undefinedp(my["addition_shield"]) ) my["addition_shield"]=my["level"]/3;
                if( undefinedp(my["addition_damage"]) ) my["addition_damage"]=my["level"];
        } else
        {
                if( undefinedp(my["addition_armor"]) ) my["addition_armor"]=10;
                if( undefinedp(my["addition_shield"]) ) my["addition_shield"]=10;
                if( undefinedp(my["addition_damage"]) ) my["addition_damage"]=10;
        }
        ob->set_default_object(__FILE__);
        if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT_HUMAN + ( my["con"] )* 1000);
        ob->set_max_encumbrance( BASE_ENCUMBRANCE_HUMAN + my["str"] * 1200 + my["level"] * 1000);
        ob->set_max_capacity( BASE_CAPACITY_HUMAN + my["con"]*1 +my["level"]*2 );
}

mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

void reset_attribute(object ob)
{
        mapping my;
        int q_con,q_int,q_dex,q_str;
        my = ob->query_entire_dbase();
        q_con = ob->query_con();
        q_int = ob->query_int();
        q_str = ob->query_str();
        q_dex = ob->query_dex();
        my["heart_beat_rate"] = 6;
        if(userp(ob))
        {

                my["max_hp"] = ( 40 + ( q_con * 20 ) );
                my["max_mp"] = ( 30 + ( q_int * 15 ) );
                my["max_ap"] = ( 30 + ( q_con * 15 ) );

                // extra hp
                my["max_hp"] += ob->query_temp("apply/hp");
                my["max_hp"] += ob->query("addition/hp");
                // extra mp
                my["max_mp"] += ob->query_temp("apply/mp");
                my["max_mp"] += ob->query("addition/mp");
                // extra ap
                my["max_ap"] += ob->query_temp("apply/ap");
                my["max_ap"] += ob->query("addition/ap");


               // 人類等等: 為平均的成長.

                my["Merits"]["bio"]=(q_con+q_dex)/30;
                my["Merits"]["bar"]=(q_con+q_str)/30;
                my["Merits"]["wit"]=(q_int+q_dex)/30;
                my["Merits"]["sou"]=(q_int+q_str)/30;
                my["Merits"]["tec"]=(q_int+q_con)/30;
        }
        ob->set_max_encumbrance( BASE_ENCUMBRANCE_HUMAN + (ob->query_str()*1350) + my["level"]*1000);
        ob->set_max_capacity( BASE_CAPACITY_HUMAN + (ob->query_con()*1)+my["level"]*2 );
        ob->set_weight(BASE_WEIGHT_HUMAN + ( my["con"] )* 1000);
        return;
}

int can_wear(string type) {
        return 1;       // 所有狀備都行
}

