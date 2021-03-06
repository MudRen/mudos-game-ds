#include <ansi.h>

inherit NPC;

void create()
{
        set_name("薨", ({ "hong","hong" }) );
        set("race","human");
        set("gender", "女性");
        set("level",28);
        set("age",25);
        set("evil",-15);
        set("title",HIR"聖炎夢使"NOR);
        set("long",@LONG
她的臉龐被金製的修羅面具遮住了大部份，令人不知道她的
真正面目，據說看過她真面目的人都已死於她的炎術之下，
最擅長的是將火炎聚集壓縮成炎球，再以放射的方式攻擊敵
人。
LONG
);
        setup(); 
        carry_object(__DIR__"../eq/sl_mask")->wear();
        carry_object(__DIR__"../wp/wind_soul")->wield();
}

int special_attack(object me,object target,int hitchance)
{
    int tdex,tdod;
    if(!me || !target) return 0;
    if(random(4) ) return 0;
    tdex=target->query_dex();
    tdod=target->query_skill("dodge");
    if(random(hitchance/2) > tdex+tdod)
    {
      message_vision("\n"
                    +HIR"$N將火炎分散成數十顆火炎球，聚集在雙手上......\n"
                    +"$N雙手一揮，數十顆火球如天女散花般射向$n......\n"
                    +"$n被許\多顆火球擊中，受到不小的傷害！！！\n\n"NOR
                    ,me,target);
      target->receive_damage("hp",random(30)+random(30)+random(30)+random(30)+random(30));
      return 1; 
    }
    else
    {
      message_vision("\n"
                    +HIR"$N將火炎分散成數十顆火炎球，聚集在雙手上......\n"
                    +"$N雙手一揮，數十顆火球如天女散花般射向$n......\n"
                    +"$n敏捷地東躲西閃，雖然閃過大部份攻擊，但仍然被擊中一兩下......\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",random(30)+random(30));
      return 1;
    }
}
