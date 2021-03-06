// 邪極宗 共用函式
// Tmr 2007/10/11
//

#include <ansi.h>

// 魔性等級：
// 天魔臨世、天魔暴起、天魔滅體、天地魔化、天魔屠神

int getMagic(object me, object target) 
{
        string temp_magic = "ancestor_" + me->query("id");
        return target->query_temp(temp_magic);
}

int getMagicLimit(int lv) 
{
        switch(lv) {
                case 1: return 2000;
                case 2: return 4000;
                case 3: return 8000;
                case 4: return 16000;
                case 5: return 32000;
        }
        return 0;
}

string getMagicLevelName(object me, object target)
{
        int magic = getMagic(me, target);

        if( magic >= getMagicLimit(4) )
                return "天魔屠神";
        if( magic >= getMagicLimit(3) )
                return "天地魔化";
        if( magic >= getMagicLimit(2) )
                return "天魔滅體";
        if( magic >= getMagicLimit(1) )
                return "天魔暴起";
       if( magic > 0 )
                return "天魔臨世";
        return "無";
}

int getMagicLevel(object me, object target)
{
        int magic = getMagic(me, target);

        if( magic >= getMagicLimit(4) )
                return 5;
        if( magic >= getMagicLimit(3) )
                return 4;
        if( magic >= getMagicLimit(2) )
                return 3;
        if( magic >= getMagicLimit(1) )
                return 2;
       if( magic > 0 )
                return 1;
        return 0;
}


// 種魔
void addMagic(object me, object target, int magic, int lv) 
{
        string temp_magic = "ancestor_" + me->query("id");
        int power = getMagic(me, target);
          if( power + magic > getMagicLimit(lv) )
                return; // 已超過容許範圍

        // 每次最多加3000點
        if(magic > 3000 ) magic = 3000;

        target->add_temp(temp_magic, magic);
}

// 刪魔
void deleteMagic(object me, object target)
{
        string temp_magic = "ancestor_" + me->query("id");
        target->delete_temp(temp_magic);
}


