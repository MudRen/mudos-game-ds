// stake.c 假人 
// 2002/04/13 -Tmr
// update -Acme-

inherit NPC;

#define LIFE 8000

void create()
{
    set_name("稻草人", ({ "scarecrow stake", "stake", "_OBJ_STAKE_" }) );
    set_race("human");
    set("long", "一個做的栩栩如生的稻草人，用來嚇阻小鳥用的。\n");

    // 假人的生命值
    set("stake_life",LIFE);
    setup();
    delete_stat("hp");
}

int accept_fight(object ob)
{
    return 1;
}

varargs int attack(object opponent)
{
        //假人不會攻擊
        return 0;
}
int defend(int ability, int strength, object from)
{
        // 無法成功防禦
        return 0;
}

int absorb(int ability, int strength, object from)
{
        // 無法接受力道
        return 0;
}

//假人沒有防禦值
int resist_damage(int damage, object from_ob)
{
        return 0;
}

varargs int receive_damage(int damage, object from, object attacker)
{

        string skill;
        // 沒有攻擊者
        if(!attacker) return 0;
        skill=attacker->query_temp("attack_skill");
        //沒有攻擊技能，不給經驗值
        if(!stringp(skill)) return 0;
        // 判斷攻擊的技能，大於 50 級，則將無法利用假人練功。
        if( attacker->query_skill(skill,1) >= 50) return 0;


        // 假人的生命 判斷
        add("stake_life",-damage);
        if( query("stake_life")<0 ) {
                message_vision("「喀啦」數聲響，$N變成花花碎片，散落滿地了。\n",this_object());
                remove_all_killer();
                call_out( (:destruct($1):),1,this_object());
        }       
        return damage;
}

