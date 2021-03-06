#include <ansi.h>
inherit NPC;
void create()
{
        set_name("上官濟雲",({"master shang-guan","shang-guan","master"}));
         set("long" ,@LONG
    上官家族的佼佼者，上官聚的長兄，少年就以天邪劍法、與
傲霜冰心訣稱霸南武林，與軒轅烈、吳鍾並列三大之最之一的天
最，但年老後厭倦江湖的是非瑣碎事，所以引退於上官之家東南
方，自創萬仙派，隱居自天雷山莊，不管江湖恩怨。
LONG
        );

        set("nickname", HIY"天澤聖人"NOR );
        set("attitude", "friendly"); 
        set("age", 55);
        set("gender","男性");
        set("combat_exp", 120000);
        set("level", 55);
        set("title",HIY "萬仙派開創哲人" NOR );
        set("max_ap",4000);
        set("max_hp",30000);
        set("class1","萬仙派");
        set("flurrydodge",1);
        create_family("萬仙派",10,"開創哲人");
        set_temp("apply/armor",40);
        set_skill("fogseven",85);
        set_temp("sorgitimes",10);
        set_skill("unarmed", 80);

        set_skill("sword",90);
        set_skill("moon_force",50);
        set_skill("dodge", 80);
        set_skill("force", 70);
        set_skill("parry", 100);
        set_skill("sorgi_sword",80);
        map_skill("sword","sorgi_sword");
        map_skill("dodge","fogseven");
        set("guild_gifts",({ 4,6,4,6 }));
        set("guild_skills",([
  "dodge" : ({ 100,3,90 }),
  "parry" : ({ 110,3,80 }),
  "unarmed":({ 130,2,60 }),
  "sorgi_sword" : ({ 150,3,80 }),
  "moon_force" : ({ 175,4,85 }),
  "force" : ({ 135,3,85 }),
  "sword" : ({ 100,3,80 }),
  "fogseven" : ({ 140,3,80 }),
]));
        set("no_check_class",1);
        set("adv_class",1);
        set("chat_chance",8);
        set_temp("class_wind/power",200);

        set("chat_msg", ({
    (:command("sigh"):),
  (:command("exert moon_force recover"):),
}));
        set("chat_chance_combat",40);
        set("chat_msg_combat",({
  (:command,"exert sorgi_sword":),
  (:command,"exert sorgi_sword":),
  (:command("exert moon_force moon-arc"):),
}));

        //set("inquiry/小狅","他就是我兒子，有什麼事嗎？\n");
        setup();
        //carry_object(__DIR__"wp/shangsword")->wield();
        //carry_object(__DIR__"eq/sandal")->wear();
}

void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");

        add_action("do_advance","advance");
        add_action("do_join","join");
}

int do_skill_list(string arg)
{
        return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int do_skill_train(string arg)
{
        
        if( arg=="moon_force" )
        {
                if( this_player()->query_skill( "moon_force", 1 ) == 0 )
                return notify_fail("你並沒有殘月心法基礎，因此無法修練。\n");
        }
        return GUILDMASTER->do_skill_train(this_object(),this_player(),arg); 
}

int do_join(string arg)
{
        object ob=this_object() , me=this_player();

        string gender;

        if( !arg && !me->query_temp("join_f") )
                return notify_fail("請問要加入什麼門派？\n");
        if( me->query_temp("join_f") && !arg ) arg = "萬仙派";
        if( strsrch(arg, "萬仙派") == -1 || strsrch(arg, "不") > -1)
                return notify_fail("請問要加入什麼門派？\n");
        if( me->query("gender") == "女姓" ) gender="女俠";
        else gender = "少?";
    message_vision("$N想加入"HIY"萬仙派。\n"NOR,me); 

        if( me->query("class1") )
                return notify_fail("你已是"+me->query("class1")+"裡的刀客了。\n");
        if( me->query("family/family_name")=="萬仙派" )
                return notify_fail("你已是萬仙派的刀客了。\n");
                command("cong "+me->query("id"));
                message("world:world1:vision",
        HIG "\n\t上官濟雲說道  "HIW+me->name(1)+HIY""HIG"加入我萬仙派，請各位英雄好漢多多照顧！！\n"NOR
        ,users() );

                message_vision("$N成為萬仙派的弟子，追隨上官濟雲的一切。\n",me);
                
                me->set("class1","萬仙派");
                me->create_family("萬仙派",4,"刀客");
                me->set("adv_class",1);
                return 1;
        }
//      return 1;


int do_advance(string arg)
{
        if (this_player()->query("family/family_name")=="萬仙派") return GUILDMASTER->do_advance(this_object(),this_player(),arg);
        else return notify_fail("你並非萬仙派的弟子。\n");
}


string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");

        lv = lv/10;     // 將 rank 分為六個層次

        if( me->query("gender") == "男性" )
        {
                switch( lv )
                {
                                // LV 1 ~ 9
                        case 0: rank = "萬仙派第四代刀客"; break;
                                // LV 10 ~ 19
                        case 1: rank = HIB"萬仙刀客駕輕就熟"NOR; break;
                                // LV 20 ~ 29
                        case 2: rank = HIC"萬仙派之頂尖刀客"NOR; break;
                                // LV 30 ~ 39
                        case 3: rank = HIM"刀亦隨刀亦隨風行"NOR; break;
                                // LV 40 ~ 49
                        case 4: rank = HIG"縱橫刀場數一豪傑"NOR; break;
                                // LV 50
                        default: rank = HIW "萬仙傳奇刀場神話" NOR;
                }
        }
        else
        {
                switch( lv )
                {
                                // LV 1 ~ 9
                        case 0: rank = "萬仙派第四代刀客"; break;
                                // LV 10 ~ 19
                        case 1: rank = HIB"萬仙女刀隨心所欲"NOR; break;
                                // LV 20 ~ 29
                        case 2: rank = HIC"萬仙女?強絕天下"NOR; break;
                                // LV 30 ~ 39

                        case 3: rank = HIM"心刀並其萬仙合一"NOR; break;
                                // LV 40 ~ 49
                        case 4: rank = HIG"刀下亡魂數以萬計"NOR; break;
                                // LV 50
                        default: rank = HIY "萬仙傳奇刀場神話" NOR;
                }

        }
        return rank;
}


void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
HIW"\n【武林傳聞】"HIY"萬仙派開創哲人 "NOR"上官濟雲 "HIG"被武林新起勢力 "HIC+ob->name(1)+NOR" "HIG"殺死了！！\n\n"+NOR
        ,users());

        ob->add("popularity", 3); 
        ::die();
        //destruct(this_object());
        return;
}

