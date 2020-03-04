#include <ansi.h>

// 獎勵
private void do_bonus()
{
        string msg;
        int i;
        object* obs;

        msg = HIC "\n\t樹林隙縫間一線一線的陽光，好像久遠以來時間的幕紗，一層一層掩映，一層一層飄忽迷離。\n"
                "\t雨點滴滴答答地落下來，淅瀝瀝、嘩啦啦地地下著個不停，沖走了灰塵和落葉。\n"
                "\t生物們都因為這場"HIG"「牧神之雨」"HIC"，長得更加茁壯了。\n\n" NOR;

        obs = users();
        message("world:world1:vision", msg, obs);
        for( i=0;i<sizeof(obs);i++) {
                // 不在戶外
                if( !environment(obs[i]) ) continue;
                if( !environment(obs[i])->query("outdoors") ) continue;
                tell_object( obs[i], HIG "你感受到牧神之雨的生命力，讓你的修為更上一步。\n" NOR);
                obs[i]->add("war_art", 1 + random(3) );
                obs[i]->add("exp", 10000 + random(10000) );
        }
}

// 事件觸發
void trigger_event()
{
                 do_bonus();
                
}

void create() 
{ 
        seteuid(getuid()); 
}

