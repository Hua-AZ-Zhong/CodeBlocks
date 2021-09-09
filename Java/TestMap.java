import java.util.HashMap;
import java.util.Map;

public class TestMap {
 
    private static Map<String, String[]> map = new HashMap();
 
    static {
        map.put("X01001",new String[]{"ATM存款","01","存款-X01"});
        map.put("X02001",new String[]{"贷记","01","贷记-X02"});
        map.put("X03001",new String[]{"转账拆分的转入（转出方付费）","01","转账转入-X03"});
    }

    public static void main(String[] args) {
        System.out.println(map.get("X02001")[0]);
        System.out.println(map.get("X02001")[1]);
        System.out.println(map.get("X02001")[2]);
    }

}