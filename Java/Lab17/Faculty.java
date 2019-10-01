public class Faculty extends Employee {
    private static final long serialVersionUID = 1L;
    private String office_hour;
    private int rank;

    public static final int LACTURE = 0;
    public static final int ASSISTANT_PROFESSOR = 1;
    public static final int ASSOCIATE_PROFESSOR = 2;
    public static final int PROFESSOR = 3;

    Faculty(String name, String address, String phone_number, String email_address, String office, int salary,
            String office_hour, int rank) {
        super(name, address, phone_number, email_address, office, salary);
        this.office_hour = office_hour;
        this.rank = rank;
    }

    public String getOffice_hour() {
        return this.office_hour;
    }

    public void setOffice_hour(String office_hour) {
        this.office_hour = office_hour;
    }

    public int getRank() {
        return this.rank;
    }

    public void setRank(int rank) {
        this.rank = rank;
    }

    @Override
    public String toString() {
        String rank_name = "";
        switch (rank) {
        case LACTURE:
            rank_name = "lacture";
            break;
        case ASSISTANT_PROFESSOR:
            rank_name = "assistant professor";
            break;
        case ASSOCIATE_PROFESSOR:
            rank_name = "associate professor";
            break;
        case PROFESSOR:
            rank_name = "professor";
            break;
        default:
            rank_name = "no rank";
            break;
        }
        return super.toString() + "\nOffice hour " + office_hour + "\nRank " + rank_name;
    }
}