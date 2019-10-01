import java.util.Date;

public class Employee extends Person {
    private static final long serialVersionUID = 1L;
    private String office;
    private int salary;
    private Date date_hired;

    public Employee(String name, String address, String phone_number, String email_address, String office, int salary) {
        super(name, address, phone_number, email_address);
        this.office = office;
        this.salary = salary;
        date_hired = new Date();
    }

    public String getOffice() {
        return office;
    }

    public void setOffice(String office) {
        this.office = office;
    }

    public int getSalary() {
        return salary;
    }

    public void setSalary(int salary) {
        this.salary = salary;
    }

    public java.util.Date getDate_hired() {
        return date_hired;
    }

    @Override
    public String toString() {
        return super.toString() + "\nOffice " + office + "\nSalary " + salary + "\nDate hired " + date_hired;
    }
}