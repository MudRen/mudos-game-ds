// enhanced.c �Z��/����j�Ʊ��b
// Tmr 2007/04/26

// Tmr 2007/07/11 �[�W�i�s���b���W��

#include <ansi.h>

// �j�ƥi���\����
#define MAX_TIMES 7

int getMaxTimes() { return MAX_TIMES; }

// ���b���|
#define SCROLL_PATH "/open/enhance/"

#define LV5_SET ({ \
        "100_str", "100_dex", "100_int", "100_str", \
        "100_hp", "100_ap", "100_mp", \
        "100_atk", "100_def", "100_shd", \
})

#define LV10_SET ({ \
        "60_hp", "60_ap", "60_mp", \
        "60_atk", "60_def", "60_shd", \
})

#define LV15_SET ({ \
        "70_hp", "70_ap", "70_mp", \
        "70_atk", "70_def", "70_shd", \
})

#define LV20_SET ({ \
        "60_str", "60_int", "60_dex", "60_con", \
        "10_hp", "10_ap", "10_mp", \
        "10_atk", "10_def", "10_shd", \
})

#define LV30_SET ({ \
        "70_str", "70_int", "70_dex", "70_con", \
        "30_hp", "30_ap", "30_mp", \
        "30_atk", "30_def", "30_shd", \
})

#define LV40_SET ({ \
        "10_str", "10_int", "10_dex", "10_con", \
})

#define LV45_SET ({ \
        "30_str", "30_int", "30_dex", "30_con", \
})

#define LV50_SET ({ \
        "10_bar", "10_bio", "10_wit", "10_sou", "10_tec", \
        "10_hit_r", "10_hit_p", "10_hit_d", \
})

#define LV60_SET ({ \
        "30_bar", "30_bio", "30_wit", "30_sou", "30_tec", \
        "30_hit_r", "30_hit_p", "30_hit_d", \
})

// ���a�i�H�x�s���� scroll �i��
#define MAX_DEPOT 200
#define DEPOT_PER_LEVEL 16
#define DEPOSIT_COST 100

int getMaxDepot(object me) {
        if(!me) return MAX_DEPOT;
        if(me->query("level")<=50) return MAX_DEPOT;
        return MAX_DEPOT + (me->query("level")-50) * DEPOT_PER_LEVEL;
}

void depositScroll(object me, object scroll)
{
        if( !scroll->query("is_enhance") ) {
                tell_object(me, "�o���O�@�i�j�Ʊ��b�C\n");
                return;
        }

        if(me->query("bank/past") < DEPOSIT_COST ) {
                tell_object(me, "�A���s�ڤ����A�L�k�x�s���b�C\n");
                return;
        }

        if( me->getDepotSize() >= getMaxDepot(me) ) {
                tell_object(me, "�A�ӤH���b�ܮw�w�g���F�A�L�k�A�s�J��h�F��C\n");
                return;
        }

        me->add("bank/past", -DEPOSIT_COST);
        me->depotItem( base_name(scroll) );

        tell_object(me, "�A�N"+ scroll->query("name") + "�s�J�ӤH���b�ܮw�C\n" NOR);
        destruct(scroll);
}

void withdrawScroll(object me, int idx)
{
        int size;
        object ob;

    size = me->getDepotSize();
        
        if( idx < 0 || idx >= size) {
                tell_object(me, "�A���ӤH���b�ܮw���A�èS���o�@�i���b�C\n");
                return;
        }

        ob = new(me->getDepotItem(idx));
    if( !objectp(ob) ) {
                tell_object(me, "�ثe�L�k��X�o�i���b�A�гq���Ův�B�z�C\n");
                return;
        }

        if(!ob->move(me) ) {
                tell_object(me, "�A���W���F��Ӧh�F�A�L�k��X���b�C\n");
        destruct(ob);
                return;
        }
        
        me->deleteDepotItem(idx);
        tell_object(me, "�A�q�ӤH���b�ܮw����X"+ ob->query("name") + "�C\n" NOR);
}


// �Q�� id �ӧ� scroll
void withdrawScroll_ID(object me, string id)
{
        int idx, size;
        object ob;

        size = me->getDepotSize();
        if( size <= 0) {
                tell_object(me, "�A���ӤH���b�ܮw���A�S��������b�C\n");
                return;
        }

        for(idx = 0;idx < size;idx++) {
            ob = new(me->getDepotItem(idx));
            if( !objectp(ob) ) continue;
                if( strsrch(ob->query("id"), id) != -1 ) {
                        destruct(ob);
                        withdrawScroll(me, idx);
                        return ;
                }
                destruct(ob);
        }
        
    tell_object(me, "�A���ӤH���b�ܮw���A�S���o�ب��b�C\n" NOR);
}

string listScroll(object me)
{
        int i, size, ct;
        string msg;
        string* items;
        object ob;

        items = me->getAllDepotItems();
    size = sizeof(items);

    msg  = HIY"�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n"NOR;
    msg += sprintf("�ثe�x�s�� %4d/%4d �i���b\n", size, getMaxDepot(me) );
    msg  += HIY"�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n"NOR;
    for(i=0, ct = 1;i<size;i++, ct++) {
        if( !objectp(ob = load_object(items[i])) ) continue;
        msg += sprintf("%4d�G%24s" NOR, i, ob->query("name"));
        if(ct==4) {     // �|���N����
                msg+="\n";
                ct = 0;
        }
        destruct(ob);
    }
    msg  += HIY"\n�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n"NOR;

//      me->start_more(msg);
        return msg;
}


// �������v
int isDropScroll() {
        // 1%
        return (random(100) == 1);
}

string* possbileScrollSet(int lv)
{
        string* set = ({});
        if(lv<5) return set;
        if(lv>=5) set += LV5_SET;
        if(lv>=10) set += LV10_SET;
        if(lv>=15) set += LV15_SET;
        if(lv>=20) set += LV20_SET;
        if(lv>=30) set += LV30_SET;
        if(lv>=40) set += LV40_SET;
        if(lv>=45) set += LV45_SET;
        if(lv>=50) set += LV50_SET;
        if(lv>=60) set += LV60_SET;

        return set;
}


int success(int p)
{
        return random(100) < p;
}

int release = 0;

int getTotal() { return release; }

// ���ͱ��b�A��NPC���ŧP�_
object createScroll(int lv)
{
        int size;
        string *set = possbileScrollSet(lv);
        size = sizeof(set);
        if( size == 0) 
                return 0;       // �S�������i�H��
        release++; // ���X��+1
        return new( SCROLL_PATH + set[random(size)] + ".c");
}

int count(string type, int p)
{
        switch(type) {
                case "str": case "dex": case "con": case "int":
                     if( p == 100 ) return 1;
                     if( p == 60 ) return 2;
                     if( p == 70 ) return 2;
                     if( p == 30 ) return 5;
                     return 5;
                case "hp": case "mp": case "ap":
                        if( p == 100 ) return 20;
                        if( p == 60 ) return 40;
                        if( p == 70 ) return 40;
                        if( p == 30 ) return 90;
                        return 90;
               case "damage":
                        if( p == 100 ) return 2;
                        if( p == 60 ) return 5;
                        if( p == 70 ) return 5;
                        if( p == 30 ) return 9;
                        return 9;
                case "shield": case "armor":
                        if( p == 100 ) return 5;
                        if( p == 60 ) return 10;
                        if( p == 70 ) return 10;
                        if( p == 30 ) return 20;
                        return 20;
                case "bar": case "bio": case "wit": case "sou": case "tec":
                      return 1;
                case "hit_r": case "hit_d": // �����v�B�������
                        if( p == 100 ) return 1;
                        if( p == 60 ) return 1;
                        if( p == 70 ) return 1;
                        if( p == 30 ) return 4;
                        return 2;
                case "hit_p": // �����ˮ`
                        if( p == 100 ) return 3;
                        if( p == 60 ) return 6;
                        if( p == 70 ) return 6;
                        if( p == 30 ) return 20;
                        return 10;
        }
        return 0;
}


void enhanceObj(object scroll, object obj, string prop) 
{
        string type;
        int eff;

        type = scroll->query("eff_type");
        eff = count(type, scroll->query("eff_p"));
        
        obj->add( prop + "/" + type, eff);
}

int enhance(object scroll, object obj) 
{
        string prop, eff_type;
        if( !scroll->query("is_enhance") ) {
                write("�o���O�@�i�j�Ʊ��b�C\n");
                return 1;
        }

         prop = obj->query("armor_prop") ? "armor_prop" : "NULL";
         if( prop == "NULL" && obj->query("skill_type") )
                prop = "weapon_prop";

         if( prop != "armor_prop" && prop != "weapon_prop")  {
                write("�j�Ʊ��b�u��Φb�Z���Ψ���W���C\n");
                return 1;
        }


        if( obj->query("equipped") ) {
                write("�Х���o��˳Ʈ��U�ӡC\n");
                return 1;
        }


        if( obj->query_autoload() ) {
                write("�j�Ʊ��b�L�k�ϥΦb save item �W�C\n");
                return 1;
        }

        if( obj->query("enhance_times") >= MAX_TIMES ) {
                write("�o�󪫫~�w�g�W�L�i���\\���j�Ʀ��ƤF�C\n");
                return 1;
        }
        
        obj->add("enhance_times",1);    // ���ƥ[1
        eff_type = scroll->query("effect_type");

        if( success(scroll->query("eff_p") ) ) {
       message_vision( HIY "$N"HIY"�o�X�벴�����~�A$n"HIY"�ܪ����@�ˤF�C\n" NOR, scroll, obj);
                enhanceObj(scroll, obj, prop);
        obj->add("long",
                     sprintf( HBK "[%s] �ϥ� %s " HIW "���\\�C\n" NOR, ctime(time()), scroll->query("name")  ) );
        } else {
                if( (scroll->query("eff_p") == 30 || scroll->query("eff_p") == 70) 
                        && random(100) > 50 ) {
                        // ���c�ʽ�A��50%���v�|���a����
                                message_vision( HBK "$N"HBK"�P$n"HBK"�@�_�Ƨ@���ƪ��·ϡA���W�N�Q���j���A���������F�I�I\n" NOR, scroll, obj);
                            destruct(obj);
                                        destruct(scroll);
                                                return -1;       // ��ܽ��a��
                } else {
                        message_vision( HBK "$N"HBK"�Ƨ@�@�}���ϡA���W�N�Q���j���F�A��$n"HBK"�S��������ܡC\n" NOR, scroll, obj);
                                obj->add("long",
                            sprintf( HBK "[%s] �ϥ� %s "HBK"���ѡC\n" NOR, ctime(time()), scroll->query("name")  ) );
                }
        }

        destruct(scroll);

        return 1;
}

void create() 
{ 
        seteuid(getuid()); 
}

