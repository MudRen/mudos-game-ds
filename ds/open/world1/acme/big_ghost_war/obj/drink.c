/* write by -Acme-
*/

inherit ITEM;
inherit F_WATER;

void create()
{
    switch( random(3) ) {
        case 0:
            set_name("�]��s", ({ "fiend kee wine", "wine" }) );
            set("long", "�@�ӵo�۬���w�w�a�۷��������s�C");
            set("value", 1500);    
            set("heal_hp", random(200)+1);
            set("heal_ap", random(200)+1);
            set("heal_mp", random(200)+1);
            break;
        case 1:
            set_name("�����", ({ "evil kee broth", "broth" }) );
            set("long", "�@�ӵo�۵���w�w�a�۷����������C");
            set("value", 1300);    
            set("heal_hp", random(150)+1);
            set("heal_ap", random(150)+1);
            set("heal_mp", random(150)+1);
            break;
        default:
            set_name("�����", ({ "ghost kee water", "water" }) );
            set("long", "�@�ӵo�۪w�w�a�۷������զ���C");
            set("value", 1000);    
            set("heal_hp", random(100)+1);
            set("heal_ap", random(100)+1);
            set("heal_mp", random(100)+1);
            set("water_remaining", 3);
            break; 
    }
    set_weight(100);
    set("unit", "�~");
    set("water_remaining", 3);
    setup();
}
