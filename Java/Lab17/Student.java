public class Student extends Person {
    private static final long serialVersionUID = 1L;
    public static final int FRESHMAN = 0;
    public static final int SOPHOMORE = 1;
    public static final int JUNIOR = 2;
    public static final int SENIOR = 3;
    private int status;

    Student(String name, String address, String phone_number, String email_address, int status) {
        super(name, address, phone_number, email_address);
        this.status = status;
    }

    public int getStatus() {
        return status;
    }

    public void setStatus(int status) {
        this.status = status;
    }

    @Override
    public String toString() {
        String status_name = "";
        switch (status) {
        case FRESHMAN:
            status_name = "freshman";
            break;
        case JUNIOR:
            status_name = "junior";
            break;
        case SENIOR:
            status_name = "senior";
            break;
        case SOPHOMORE:
            status_name = "sophomore";
            break;
        default:
            status_name = "no status";
            break;
        }
        return super.toString() + "\nStatus " + status_name;
    }
}