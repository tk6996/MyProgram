public class Staff extends Employee {
    private static final long serialVersionUID = 1L;
    private String title;

    Staff(String name, String address, String phone_number, String email_address, String office, int salary,
            String title) {
        super(name, address, phone_number, email_address, office, salary);
        this.title = title;
    }

    public String getTitle() {
        return this.title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    @Override
    public String toString() {
        return super.toString() + "\nTitle " + title;
    }
}
